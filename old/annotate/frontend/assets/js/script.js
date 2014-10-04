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
    wrist.set_shader_width = function(shader, proportion){
      var percentage = (100 * proportion) + '%';
      shader.css('width', percentage);
    }
    return wrist
  })();
  $('#video').bind('timeupdate', function() {
    wrist.set_shader_width(wrist.shader, wrist.video_completion(wrist.video));
  });
  $('button').click(function(){
    $('#crack-time').show();
    wrist.set_shader_width($('#crack-time'), wrist.video_completion(wrist.video));
  });
});


transition = function() {
  $('img.waveform').attr('src', 'apple-touch-icon.png');
  $('video#video').attr('src', '');
  wrist.set_shader_width($('.shader'), 0);
  $('video#video source').remove();
}

load_subtrial = function(path) {
  // Path is like '/!/000/000/almost/'
  $('img#audio').attr('src', path + 'audio.png');
  $('img#emg1').attr('src', path + 'emg1.png');
  $('img#emg2').attr('src', path + 'emg2.png');
  $('#video').html('<source src="' + path + 'video.ogg" />');
}
