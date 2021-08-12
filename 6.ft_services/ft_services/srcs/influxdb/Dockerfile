# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:47:05 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:24:05 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add openrc influxdb

COPY    influxdb.conf /etc/

COPY ./setup.sh ./
RUN chmod +x ./setup.sh

EXPOSE 8086

ENTRYPOINT sh setup.sh