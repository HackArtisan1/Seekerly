#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xED };  // MAC address of your Ethernet shield/module
EthernetServer server(80);  // Port 80 for HTTP communication

const char htmlContent[] PROGMEM = R"(
<!DOCTYPE html>
<html lang='en'>

<head>
	<meta charset='UTF-8'>
	<title>NikoGuru</title>
	<meta charset='UTF-8'>
	<meta http-equiv='X-UA-Compatible' content='IE=edge'>
	<meta name='viewport' content='width=device-width, initial-scale=1.0'>
	<title>Wikipedia Search Engine</title>
	<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/normalize/7.0.0/normalize.min.css'>
	<link rel='stylesheet' href='https://azzexx.github.io/Seekerly/dist/style.css'>
</head>

<body>
	<!-- partial:index.partial.html -->
	<div class='main'>
		<div class='home'>
			<div class='container'>
				<div class='row'>
					<div class='eight columns offset-by-two'>
						<form action='' class='wiki-search-form'>
							<input type='search' placeholder='Search' class='wiki-search-input'
								id='wiki-search-input'>
							<button class='button btn btn-wiki'>Enter</button>
							<a class='button btn btn-lucky' href='http://en.wikipedia.org/wiki/Special:Random'
								target='_blank'>I'm Feeling Lucky</a>
						</form>
					</div>

					<div class='row'>
						<div class='eight columns offset-by-two' style="justify-content: center; display: flex; gap: 5px;">
							Explore <p id="demo"></p> documents
						</div>
					</div>

					<script>
						let x = Math.floor((Math.random() * 8100100) + 1);
						document.getElementById("demo").innerHTML = x;
					</script>

					<img src='https://azzexx.github.io/Seekerly/guru_b.png'>
				</div>
			</div>
		</div>

		<!-- Results Page -->

		<div class='result hidden'>
			<header class='header'>
				<div class='container'>
					<div class='row'>
						<div class='two-thirds column'>
							<form action='' class='result-wiki-search-form'>
								<input type='text' placeholder='Search Seekerly...'
									class='result-wiki-search-form-input' id='result-wiki-search-form-input'>
								<button class='btn result-btn-wiki'>Enter</button>
							</form>
						</div>
						<a href='http://172.16.1.147/'>
							<div class='one-third column'>
								<img src='https://azzexx.github.io/Seekerly/guru_b.png'>
							</div>
						</a>
					</div>
				</div>
			</header>

			<div class='container'>
				<section class='search-results'>
					<div class='one-half column'>
						<div class='display-results'></div>
					</div>
				</section>

			</div> <!-- Container -->
		</div> <!-- Results -->

	</div>
	<!-- partial -->
	<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script>
	<script src='https://azzexx.github.io/Seekerly/dist/script.js'></script>
	<script src='https://azzexx.github.io/Seekerly/dist/build.js'></script>

</body>

</html>
)";

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);  // Initialize Ethernet connection
  server.begin();  // Start the server
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());  // Print the IP address of the Arduino
}

void loop() {
  EthernetClient client = server.available();  // Check for incoming client requests

  if (client) {
    Serial.println("Connected");
    while (client.connected()) {
      if (client.available()) {
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();  // Empty line to separate headers from the body
        
        // Loop through PROGMEM to read and send HTML content
        const char* p = htmlContent;
        while (pgm_read_byte(p) != '\0') {
          client.write(pgm_read_byte(p++));
        }

        delay(1);  // Allow time for the response to be sent
        client.stop();  // Close the connection
      }
    }
  }
}
