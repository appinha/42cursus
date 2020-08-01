# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:39:34 by apuchill          #+#    #+#              #
#    Updated: 2020/07/12 18:07:48 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Select image from Dockerhub - Debian Buster @ https://hub.docker.com/_/debian
FROM debian:buster

# Run installation non-interactively (faster)
ARG DEBIAN_FRONTEND=noninteractive

# Copy setup files to container
COPY srcs /tmp/

# Install OS updates and webserver tools
# * -y: Automatic yes to prompts; assume "yes" as answer to all prompts and run
#		non-interactively.
RUN apt-get update && apt-get upgrade -u && apt-get install -y \
	nginx openssl mariadb-server php7.3 php-fpm php-mysql php-cli php-mbstring

# Run setup script
RUN bash /tmp/setup.sh

# Start services
ENTRYPOINT bash /tmp/services.sh
