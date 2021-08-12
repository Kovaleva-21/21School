# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:47:27 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:23:13 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx openssl openssh supervisor

COPY ./nginx_localhost /etc/nginx/conf.d/default.conf
COPY ./supervisord.conf /etc/supervisord.conf

RUN mkdir -p /etc/nginx/ssl

RUN  openssl req -x509 -nodes -days 3650 -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt \
        -subj "/C=RU/ST=Moscow/l=Moscow/O=21school/CN=ccorliss"

COPY ./setup.sh ./

RUN mkdir -p /run/nginx

RUN mkdir -p /var/www/nginx_localhost
RUN chmod +x ./setup.sh

EXPOSE 80 443
CMD ["./setup.sh"]
