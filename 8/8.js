var $popOverlay = $(".popup-overlay");
var $popWindow = $(".popWindow");
var $subscribeWindow = $(".subscribe_window");
var $popThankYouWindow = $(".thank_you_window");
var $popClose = $(".close-btn");
var $popUp = $('#popup');
var $subscribe = $('#subscribe')
$(function() {
  // Close Pop-Up after clicking on the button "Close"
  $popClose.on("click", function() {
    $popOverlay.fadeOut();
    $popWindow.fadeOut();
  });
 
  // Close Pop-Up after clicking on the Overlay
  $(document).on("click", function(event) {
    if ($(event.target).closest($popWindow).length) return;
    if ($(event.target).closest($popUp).length) return;
    $popOverlay.fadeOut();
    $popWindow.fadeOut();
    event.stopPropagation();
  });
 
  // Form Subscribe
 
$(".subscribe-form").submit(function() {
    var th = $(this);
    $.ajax({
      url: "https://api.slapform.com/butenkok97@gmail.com", 
      dataType: "json",
      method: 'POST',
      data: th.serialize()
    })
       $subscribeWindow.fadeOut();
        $popThankYouWindow.fadeIn();
      setTimeout(function() {
        th.trigger("reset");
      }, 1000); return false;
  });
});
   
$popUp.on('click', function(){
  $popOverlay.fadeIn();
  $subscribeWindow.fadeIn();
});