/** All the story stored as the array.
These are globals and should not be tampered with */
var storyArray = new Array(); 
var choiceArray = new Array(); 
var titleOfStory = "Adventure Of Dude ";
var authorOfStory = "Some Weird Name ";
  choiceArray[0] = ""; 
  choiceArray[0] += "<input class='block button' type='button' value='Choose the path of thorns ' onClick='javascript:swap(1);' />";
  choiceArray[0] += "<input class='block button' type='button' value='Choose the path of nails ' onClick='javascript:swap(2);' />";
storyArray[0] = "<p> This is where the story begins. bla dee bla. </p> "; 
  choiceArray[1] = ""; 
  choiceArray[1] += "<input class='block button' type='button' value='Choose the right path! ' onClick='javascript:swap(3);' />";
storyArray[1] = "<p> This is choice 1 </p> "; 
  choiceArray[2] = ""; 
  choiceArray[2] += "<input class='block button' type='button' value='Choose the wrong path! ' onClick='javascript:swap(3);' />";
storyArray[2] = "<p> This is choice 2 </p> "; 
storyArray[3] = "<p> And this is the end </p> "; 
  choiceArray[3] = "";