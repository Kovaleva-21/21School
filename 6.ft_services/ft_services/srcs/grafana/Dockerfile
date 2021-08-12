# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:46:54 by ccorliss          #+#    #+#              #
#    Updated: 2021/01/15 16:23:55 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add openrc
ADD https://dl.grafana.com/oss/release/grafana-7.3.6.linux-amd64.tar.gz ./
RUN tar xzvf grafana-7.3.6.linux-amd64.tar.gz

RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub && \
    wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk && \
    apk add glibc-2.28-r0.apk

COPY ./dashboard.conf.yaml /grafana-7.3.6/conf/provisioning/dashboards/dashboards.yaml
COPY ./datasources.conf.yaml /grafana-7.3.6/conf/provisioning/datasources/datasources.yaml

RUN rm -f /grafana-7.3.6/conf/provisioning/datasources/sample.yaml
RUN rm -f /grafana-7.3.6/conf/provisioning/dashboards/sample.yaml

COPY ./grafana.ini /grafana-7.3.6/conf/

COPY ./Dashboards/* /grafana-7.3.6/public/dashboards/
COPY ./setup.sh ./
RUN chmod +x ./setup.sh

EXPOSE 3000
ENTRYPOINT sh setup.sh