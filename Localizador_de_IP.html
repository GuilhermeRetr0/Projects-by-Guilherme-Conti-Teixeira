<!DOCTYPE html>
<html>
  <head>
    <title>Localizador de IP</title>
  </head>
  <body>
    <h1>Localizador de IP</h1>
    <p>Insira um endereço IP para ver sua localização:</p>
    <input type="text" id="ipAddress">
    <button onclick="getLocation()">Localizar</button>
    <div id="map"></div>

    <script>
      function getLocation() {
        var ipAddress = document.getElementById("ipAddress").value;

        fetch("https://geoip-db.com/json/" + ipAddress)
          .then(function (response) {
            return response.json();
          })
          .then(function (data) {
            var latitude = data.latitude;
            var longitude = data.longitude;

            // exibe o mapa com a localização encontrada
            var map = L.map("map").setView([latitude, longitude], 13);
            L.tileLayer(
              "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png",
              {
                attribution:
                  'Map data &copy; <a href="https://www.openstreetmap.org/">OpenStreetMap</a> contributors',
                maxZoom: 18,
              }
            ).addTo(map);
            L.marker([latitude, longitude]).addTo(map);
          })
          .catch(function (error) {
            console.log(error);
          });
      }
    </script>
  </body>
</html>
