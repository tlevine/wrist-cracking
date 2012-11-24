$(function(){
  window.wrist = (function(){
    var wrist = {};

    // Elements on the page
    wrist.video = document.getElementById('video');
    wrist.shader = $('#progress-shader');

    // How far along video?
    wrist.video_completion = function(v) {
        return v.currentTime / v.duration;
    }
    wrist.set_shader_width = function(proportion){
      var percentage = (100 * proportion) + '%';
      wrist.shader.css('width', percentage);
    }
    return wrist
  })();
})
