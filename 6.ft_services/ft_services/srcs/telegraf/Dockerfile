# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:47:48 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:24:45 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add openrc 
    

# ADD https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz ./
# RUN tar xzvf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
RUN apk update && apk upgrade -U -a
RUN apk add telegraf


# RUN     telegraf -sample-config telegraf.conf --input-filter cpu:mem --output-filter influxdb > telegraf.conf
COPY 	telegraf.conf /etc/

COPY ./setup.sh ./
RUN chmod +x ./setup.sh

ENTRYPOINT sh setup.sh