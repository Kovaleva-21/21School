FROM debian:buster

RUN apt-get update
RUN apt-get install nginx vim wget curl mariadb-server -y
RUN apt-get install php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip -y


COPY ./srcs/install.sh ./
COPY ./srcs/your_domain ./
COPY ./srcs/nginx.conf ./
COPY ./srcs/phpmyadmin.inc.php ./
COPY ./srcs/wp-config.php ./
COPY ./srcs/autoindex.sh ./
CMD bash install.sh
EXPOSE 80 443
