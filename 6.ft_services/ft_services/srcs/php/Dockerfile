# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:47:38 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 21:25:36 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx supervisor openrc php7 php7-fpm php7-mysqli php7-json php7-mbstring php7-session

ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz /etc/
RUN tar -xzf /etc/phpMyAdmin-5.0.2-all-languages.tar.gz -C /etc/ ; rm -rf /etc/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mkdir -p /run/nginx
RUN mv /etc/phpMyAdmin-5.0.2-all-languages /etc/phpmyadmin
COPY phpmyadmin.inc.php /etc/phpmyadmin/config.inc.php
COPY ./nginx_localhost /etc/nginx/conf.d/default.conf
COPY ./supervisord.conf /etc/supervisord.conf
COPY setup.sh /

EXPOSE 5000

ENTRYPOINT sh setup.sh
# CMD [ "sh" ]