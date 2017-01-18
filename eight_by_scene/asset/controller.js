var scene = {
    by: 8,
    scene_no: 0,
    drop_new_grid: function(target) {
        this.scene_no = this.scene_no + 1;
        var by = this.by,
            sceneid = 'sceneNo_' + this.scene_no;
        scene.operator[sceneid] = new Object;
        var newScene =
        $('<div></div>').
            attr('id', sceneid).
            append(function(){
            // add Header
            $(this).append( '<h1>scene no.' + scene.scene_no + '</h1>' );
            $(this).append( $('<div></div>').attr('class','frame').append(
                function() {
                    for (var i = 0; i < by; i++) {
                        var rowid = 'row_' + i;
                        scene.operator[sceneid][rowid] = new Array;
                        var row = $('<div class="' + rowid + '"></div>').append(function() {
                            // add Column
                            var col = new Array();
                            for (var j = 0; j < by; j++){
                                var colid = 'col_' + j,
                                    el = '<input class="' + colid + '">';
                                scene.operator[sceneid][rowid][j] = colid;
                                col[j] = $(el).attr('type','checkbox');
                            };
                            for (var j = 0; j < 8; j++) {
                                $(this).html(col);
                            };
                        });
                        $(this).append(row);
                    }
                }));
            }
        );
        $(target).append(newScene);
    },
    operator: new Object(),
    inspector: function (target) {
        $(target).click(function(){
            var col = $(this).attr('class');
            var row = $(this).parents().attr('class');
            var id = $(this).parents().parents().parents().attr('id');
            var chk;
            if ($(target).is(':checked')) {
                chk = true;
            } else {
                chk = false
            }
            console.log(id, row, col, chk);
        });
    }
};


$(document).ready(function(){
    scene.drop_new_grid('#storyboard');
    scene.inspector('input[type="checkbox"]');
    $('.add_new').on('click', function(){
        scene.drop_new_grid('#storyboard')
        scene.inspector('input[type="checkbox"]');
    });
});
