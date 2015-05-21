Pebble.addEventListener('showConfiguration', function(e) {
  // Show config page
  Pebble.openURL('https://google.com');
});

Pebble.addEventListener('webviewclosed',
  function(e) {
    var configuration = JSON.parse(decodeURIComponent(e.response));
    console.log('Configuration window returned: ', JSON.stringify(configuration));
  }
);
