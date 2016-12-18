window.onload = function() {
	$(window).keyup(function(e) {
	   //キー入力を配列に追加
	   inputKey.push(e.keyCode);
	   alert(e.keyCode)

	   //キー入力が保存された配列と隠しコマンドを比較
	   if (e.keyCode == 86) {

	   }
	 }
};