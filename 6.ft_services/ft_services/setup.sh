minikube start --vm-driver=virtualbox --memory=3500
eval $(minikube docker-env)
minikube addons enable metallb
kubectl apply -f ./srcs/metallb.yaml
docker build -t nginx_image ./srcs/nginx
docker build -t mysql_image ./srcs/mysql
docker build -t phpmyadmin_image ./srcs/php
docker build -t wordpress_image ./srcs/wordpress
docker build -t ftps_image ./srcs/ftps
docker build -t grafana_image ./srcs/grafana
docker build -t influxdb_image ./srcs/influxdb
docker build -t telegraf_image ./srcs/telegraf

kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/php/php.yaml
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/ftps/vsftpd.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml
kubectl apply -f ./srcs/telegraf/telegraf.yaml

minikube dashboard
# kubectl delete -f ./srcs/mysql/mysql.yaml
# kubectl delete -f ./srcs/wordpress/wordpress.yaml
# kubectl delete -f ./srcs/php/php.yaml
# kubectl delete -f ./srcs/nginx/nginx.yaml
# kubectl delete -f ./srcs/ftps/vsftpd.yaml
# kubectl delete -f ./srcs/grafana/grafana.yaml
# kubectl delete -f ./srcs/influxdb/influxdb.yaml
# kubectl delete -f ./srcs/telegraf/telegraf.yaml