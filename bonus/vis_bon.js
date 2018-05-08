var $jcan = $("#can");
var	size = 15;
var	ant;
var	rooms = new Array();
var links = new Array();
var moves = new Array();
var	st;
var	end;
var Xcen = document.getElementById('can').offsetWidth / 2;
var Ycen = document.getElementById('can').offsetHeight / 2;

document.getElementById("file").onchange = function() {
	var file = this.files[0];

	var reader = new FileReader();
	reader.onload = function(progressEvent) {
		var	lines = this.result.split('\n');
		var sw = 0;
		for (var line = 0; line < lines.length; line++) {
			if (lines[line].charAt(0) == '#' && lines[line] != "##start" && lines[line] != "##end")
				;
			else if (sw == 0) {
				ant = lines[line];
				sw = 1;
			} else if (sw == 1 && lines[line] == "##start") {
				while (lines[line].charAt(0) == '#')
					line++;
				rooms.push(lines[line].split(' '));
				st = lines[line].split(' ');
			} else if (sw == 1 && lines[line] == "##end") {
				while (lines[line].charAt(0) == '#')
					line++;
				rooms.push(lines[line].split(' '));
				end = lines[line].split(' ');
			} else if (sw == 1) {
				if (lines[line].indexOf(" ") != -1)
					rooms.push(lines[line].split(' '));
				else {
					line--;
					sw = 2;
				}
			}
			else if (sw == 2)
			{
				if (lines[line].indexOf("-") != -1)
					links.push(lines[line].split('-'));
				else
					sw = 3;
			}
			else if (sw == 3 && lines[line].indexOf("L") != -1) {
				moves.push(lines[line].split(' '));
			}
		}
		var x, y;
		for (var i = 0; i < links.length; i++) {
			for (var j = 0; j < rooms.length; j++) {
				if (links[i][0] == rooms[j][0]) {
					x = rooms[j][1];
					y = rooms[j][2];
					break ;
				}
			}
			for (var j = 0; j < rooms.length; j++) {
				if (links[i][1] == rooms[j][0]) {
					$jcan.drawLine({
						layer: true,
						strokeStyle: "white",
						x1: x * size + Xcen,
						y1: Ycen - y * size,
						x2: rooms[j][1] * size + Xcen,
						y2: Ycen - rooms[j][2] * size
					});
					break ;
				}
			}
		}
		var fstyle = "white";
		for (var i = 0; i < rooms.length; i++) {
			if (rooms[i][0] == st[0])
				fstyle = "green";
			else if (rooms[i][0] == end[0])
				fstyle = "red";
			$jcan.drawArc({
				layer: true,
				fillStyle: fstyle,
				x: rooms[i][1] * size + Xcen,
				y: Ycen - rooms[i][2] * size,
				radius: size / 2
			});
			fstyle = "white";
		}
		for (var i = 1; i <= ant; i++) {
			$jcan.drawArc({
				layer: true,
				fillStyle: "Yellow",
				name: 'L' + i,
				x: st[1] * size + Xcen,
				y: Ycen - st[2] * size,
				radius: size / 3
			});
		}
		var cur = -1;

		document.getElementById("body").onclick = function() {
			var antn;

			if (++cur >= moves.length)
				return ;
			for (var j = 0; j < moves[cur].length; j++) {
				antn = moves[cur][j].split('-');
				for (var k = 0; k < rooms.length; k++) {
					if (rooms[k][0] == antn[1])
						break ;
				}
				$jcan.animateLayer(antn[0] ,{
					x: rooms[k][1] * size + Xcen,
					y: Ycen - rooms[k][2] * size
				}, 500);
			}
		}
	};
	reader.readAsText(file);
};
