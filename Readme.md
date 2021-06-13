# Included library
 1. PubSubClient
    link Download => https://github.com/knolleary/pubsubclient
 2. Perintah menyalakan lampu
   mosquitto_pub -h ec2-3-86-238-120.compute-1.amazonaws.com -p 1883 -u jti -P password -m "nyala" -t "smartHome"
 3. Perintah Mematikan lampu
   mosquitto_pub -h ec2-3-86-238-120.compute-1.amazonaws.com -p 1883 -u jti -P password -m "mati" -t "smartHome"
 4. Perintah untuk mengatur lampu
   mosquitto_pub -h ec2-3-86-238-120.compute-1.amazonaws.com -p 1883 -u jti -P password -m "mati" -t "smartHome"
