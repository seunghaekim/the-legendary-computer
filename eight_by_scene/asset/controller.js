var scene = {
    by: 8,
    grid: '<input type=\"checkbox\" \/>',

    dropGrid: function(target) {
        g = this.grid;
        for (var i = 0; i < this.by; i++) {
            $(target).append(g)
        }
    }
};

$(document).ready(function(){
    scene.dropGrid('#storyboard');
});
