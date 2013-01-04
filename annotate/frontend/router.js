var Router = Backbone.Router.extend({
  routes: {
    // List observation options
    'observations': '',

    // Tagging screens
    'observations/:trial/:subtrial/sync': '',
    'observations/:trial/:subtrial/crack': '',
    'observations/:trial/:subtrial/done': '',
    
    // Default - catch all
    '*actions': 'defaultAction'
  }
});
