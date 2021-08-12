# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:48:07 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 17:03:17 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx supervisor openrc php7 php7-fpm php7-mysqli php7-json php7-mbstring php7-session

COPY ./nginx_localhost /etc/nginx/conf.d/default.conf
COPY ./supervisord.conf /etc/supervisord.conf


ADD https://wordpress.org/latest.tar.gz ./

RUN tar xzvf latest.tar.gz

COPY ./wp-config.php /wordpress/wp-config.php

COPY ./setup.sh ./

RUN mkdir -p /run/nginx

RUN chmod +x ./setup.sh

EXPOSE 5050

ENTRYPOINT sh setup.sh