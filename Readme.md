# Included library
 1. PubSubClient
    link Download => https://github.com/knolleary/pubsubclient
 2. Perintah menyalakan lampu
   mosquitto_pub -h ec2-3-86-238-120.compute-1.amazonaws.com -p 1883 -u jti -P password -m "lamp/on" -t "smartHome"
 3. Perintah Mematikan lampu
   mosquitto_pub -h ec2-3-86-238-120.compute-1.amazonaws.com -p 1883 -u jti -P password -m "lamp/off" -t "smartHome"
