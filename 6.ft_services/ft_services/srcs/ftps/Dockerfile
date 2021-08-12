# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:19:12 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:26:15 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add vsftpd openssl openrc

RUN mkdir -p /etc/nginx/ssl
# RUN adduser -D ccorliss
# RUN echo "root\nroot\n" | adduser ccorliss
# RUN echo 'root:root' | chpasswd

RUN echo -e "qwer\nqwer" | adduser user
RUN chown user:user /home/user/

RUN openssl req -x509 -nodes -days 3650 -newkey rsa:2048 \
        -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.pem \
        -subj "/C=RU/ST=Moscow/l=Moscow/O=21school/CN=ccorliss"
RUN     mkdir -p /home/ccorliss/

COPY ./setup.sh ./

COPY vsftpd.conf /etc/vsftpd/
RUN mkdir -p /run/openrc/
RUN touch /run/openrc/softlevel

RUN chmod +x ./setup.sh

EXPOSE  21 21000
ENTRYPOINT sh setup.sh