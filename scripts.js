var target = "https://raw.githubusercontent.com/seunghaekim/the-legendary-computer/test-bed/list-of-articles.json";

$(document).ready(function(){
    $.getJSON(target, function(result) {
        $.each(result, function(i) {
            article = result[i];
            loa_class = "article-" + i;
            $(".loa").append("<tr class=" + "\"" + loa_class + "\"" + ">");
            loa_class = ".article-" + i;
            $(loa_class).append("<td>");
            $(loa_class).append("</td>");
            $(".loa").append("</tr>");
        })
    })
})
