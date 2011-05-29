/*
  Author: Simon Symeonidis
  License: GPLv3 

  This file takes care of all the functions for adding dynamic 
  content to the files. 
*/

// This is a global to protect the animation - in other words, while animation is 
// undergoing, don't let the user click on anything else. 
var ANIMATION_LOCK = 0;
var STORE_ALL_HTML = ""; // used for storing the whole page temporarily. 

/** This is a routine which swaps between story paragraphs. jQuery makes pretty
fade in and out animations. */
function swap(swid){
  if(ANIMATION_LOCK == 0){
    ANIMATION_LOCK = 1; // Animating, lock
    $(document).ready(function(){
      // Fade out, change text, fade in 
      $('#story').fadeOut('slow', function() { 
          $(this).html(storyArray[swid]);
        }).fadeIn('slow');
      $('#choice').fadeOut('slow', function() { 
          $(this).html(choiceArray[swid]);
        }).fadeIn('slow', function(){
          ANIMATION_LOCK = 0; // Animation done, unlock
        });
    });
  }
}

/** Standard initialization routines. This part just initializes the boxes
to the first elements of storyArray and choiceArray (which are assumed to be there
by the person writting the story - ie requirement to set a blob with id 0 for
the first page...) */
function init(){
  // Set the title of story 
  $('#storytitle').html = titleOfStory;
  // Set the initial stuff to show
  $('#story').html(storyArray[0]);
  $('#choice').html(choiceArray[0]);
  if (authorOfStory != "")
    authorOfStory += " | "; 
  $('#author').html(authorOfStory);
}

/** This is the function to open the about dialog. Fades out everything, stores the
html in a global variable, and puts the other html. */
function aboutOpen(){
  var splash = '<div class="credits">\
  <h2> TinyStory </h2>\
  This is a program that is designed to generate written interactive stories to html and javascript ones.\
  <h2> Author </h2>\
  Simon (psyomn) Symeonidis\
  <br/><br/>\
  If you have any suggestions, hate or praise, feel free to send me a message at <br/><br/>\
  <a href="mailto:psyomn@xenagoras.net">psyomn@xenagoras.net</a><br/>\
  <img src="css/studios.png" />\
  <h2> Open Source Thanks! </h2>\
  <b>Tango / warszawianka </b> for the pretty icons! <br/>\
  <b>jQuery </b> for the pretty animations!<br/>\
  <br/><br/>\
  <b>[<a href="javascript:aboutClose();">BACK</a>]</b>\
  </div>'; 

  $(document).ready(function(){
    $('body').fadeOut('slow', function(){
      STORE_ALL_HTML = $('body').html();
      $('body').html(splash); 
    }).fadeIn('slow');
    // Swap the html and fade in
  });

}

/** Function to show the about info, credits, and other information. */
function aboutClose(){
  $(document).ready(function(){
    $('body').fadeOut('slow', function(){
      $('body').html(STORE_ALL_HTML);
      STORE_ALL_HTML = ""; 
    }).fadeIn('slow');
  });
}


