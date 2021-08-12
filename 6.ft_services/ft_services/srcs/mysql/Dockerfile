# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:47:16 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:24:10 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade

RUN apk add openrc mysql mysql-client
COPY ./setup.sh ./

RUN mkdir -p /etc/mysql
RUN mkdir -p /run/openrc/
RUN touch /run/openrc/softlevel
RUN chmod +x ./setup.sh
COPY ./mysql.sql ./
COPY ./wordpress.sql ./
COPY ./my.cnf /etc/
ENTRYPOINT sh setup.sh
