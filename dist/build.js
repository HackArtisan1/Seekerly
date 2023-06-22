var htmlCode = `<div class='home'>
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
</div> <!-- Results -->`;

document.addEventListener('DOMContentLoaded', function () {
        var targetElement = document.getElementById('content');
        targetElement.innerHTML = htmlCode;
});