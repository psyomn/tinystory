/**
  This is where the story should be stored as an array. 
*/

var storyArray = new Array();
var choiceArray = new Array();

// BLOB 0
storyArray[0] = "The quick brown fox jumps over the lazy dog";
  // GOTO
  choiceArray[0] =  '<input class="button block" onClick="javascript:swap(1);" type="button" value="Label 0" />';
  choiceArray[0] += '<input class="button block" onClick="javascript:swap(1);" type="button" value="Label 1" />';
  choiceArray[0] += '<input class="button block" onClick="javascript:swap(1);" type="button" value="Label 2" />';
  choiceArray[0] += '<input class="button block" onClick="javascript:swap(1);" type="button" value="Label 3" />';

storyArray[1] = "Derpa herpa herp";
  // GOTO
  choiceArray[1] = '<input onClick="javascript:swap(0);" type="button" class="button block" value="Label 0" />'; 
  choiceArray[1] += '<input onClick="javascript:swap(0);" type="button" class="button block" value="Label 0" />'; 
