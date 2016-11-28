var target = "https://raw.githubusercontent.com/seunghaekim/the-legendary-computer/test-bed/list-of-articles.json";

$(document).ready(function(){
    $.getJSON(target, function(result) {
        $.each(result, function(i) {
            inner = result[i];
            $(".loa").append("<tr class=" + "\"" + inner.product_name + "\"" + ">");
            $(".loa").append("</tr>");
        })
    })
})
