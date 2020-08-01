# ft_server

>"This is a System Administration subject. You will discover Docker and you will set up your first web server."

This folder contains solely the files required for submission.

## Contents

`@root`

* **Dockerfile** - contains the instructions for building the webserver's docker image.

`@/srcs/`

* **setup.sh** - script for setup configuration: installs and configures all requested services.
* **services.sh** - script for initialization of webserver's services.
* **autoindex.sh** - script for turning autoindex on or off.
* **testing.sh** - script (with docker commands) for testing the project.

`@/srcs/setup/`

* **nginx.conf** - NGINX's configuration file.
* **phpMyAdmin-5.0.2-english.tar.gz** - compressed files for phpMyAdmin installation.
* **wordpress-5.3.2-pt_BR.tar.gz** - compressed files for Wordpress installation.
* **config.inc.php** - phpMyAdmin's configuration file.
* **wp-config.php** - Wordpress' configuration file.
* **wordpress.sql** - Wordpress' SQL database.

---

## Study Summary

### Docker

[**Docker**](https://www.docker.com/) is a solution for the management of lightweight process containers.

An **image** is an object that you can download and reuse to instantiate new containers. Ready-made images are provided in Docker's official repositories (their "official images"), the [Docker Hub](https://hub.docker.com/).

Docker can **build images** automatically by reading the instructions from a [**Dockerfile**](https://docs.docker.com/engine/reference/builder/) - a text file that contains all commands, in order, needed to build a given image. Using `docker build` users can create an automated build that executes several command-line instructions in succession.

The build is run by the Docker daemon, not by the CLI. **Docker daemon** is a server which interacts with the operating system and performs all kinds of services.

An `ENTRYPOINT` identifies which executable should be run when a container is started from your image.

**Docker CLI commands:**

* `docker images` - List all docker images.
* `docker rmi [image_name]` - Remove image.
* `docker build -t [image_name] .` - Build an image from a Dockerfile (in current location).
* `docker run --name [container_name] image` - Start a container from an image, with a custom name.
* `docker run --name [container_name] -it -p 80:80 -p 443:443 [name]` - `-i` interactive, `-p` ports.
* `docker start|stop [container_name]` - Start or stop an existing container.
* `docker ps` - List **currently running** docker containers.
* `docker ps -a` - List **all** docker containers (running and stopped).
* `docker exec -it [container_name] sh` - Open a shell inside of an already running container.
* `docker rm [container_name]` - Remove a stopped container.

Reference: [Docker Documentation - CLI](https://docs.docker.com/engine/reference/commandline/cli/)

### NGINX

[**NGINX**](https://docs.nginx.com/nginx/admin-guide/installing-nginx/installing-nginx-open-source/?_ga=2.203137169.148315847.1594301020-870972343.1594301020) (read as "engine-x"	) is a lightweight, high-performance web server designed for high-traffic use cases.

### SSL Protocol

[**OpenSSL**](https://www.openssl.org/) is a software library for applications that secure communications over computer networks against eavesdropping or need to identify the party at the other end.

### MySQL & MariaDB

[**MySQL**](https://www.mysql.com/) is an open-source relational database management system.

[**MariaDB**](https://mariadb.org/) is a community-developed, commercially supported fork of the MySQL relational database management system, intended to remain free and open-source software under the GNU General Public License.

### phpMyAdmin

[**phpMyAdmin**](https://www.phpmyadmin.net/) is a free and open source administration tool for MySQL and MariaDB.

### Wordpress

[**WordPress**](https://en.wikipedia.org/wiki/WordPress) (WP, [WordPress.org](https://wordpress.org/)) is a free and open-source content management system (CMS) written in PHP and paired with a MySQL or MariaDB database.

* Wordpress login page: https://localhost/wordpress/wp-login.php

---

### Useful Links

**Docker**

* [Docker website](https://www.docker.com/)
* [Docker Documentation - Get Started](https://docs.docker.com/get-started/)
* [Docker Documentation - CLI (commands)](https://docs.docker.com/engine/reference/commandline/cli/)
* [Dockerfile reference](https://docs.docker.com/engine/reference/builder/)
* [Best practices for writing Dockerfiles](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)
* [Docker Hub](https://hub.docker.com/) (image repository)

**Debian**

* [Debian image on Docker Hub](https://hub.docker.com/_/debian)
* [Debian wiki](https://wiki.debian.org/Docker)

**Webserver Tutorial**

* [LEMP (Linux, (E)NGINX, MySQL, PHP) stack tutorial](https://www.linuxbabe.com/debian/install-lemp-stack-debian-10-buster)

**NGINX**

* [NGINX (open source version)](https://docs.nginx.com/nginx/admin-guide/installing-nginx/installing-nginx-open-source/?_ga=2.203137169.148315847.1594301020-870972343.1594301020)
* [NGINX configuration](https://www.linode.com/docs/web-servers/nginx/how-to-configure-nginx/)
* [NGINX redirection from HTTP to HTTPS (SSL)](https://www.hostinger.com.br/tutoriais/nginx-redirect-http-to-https/)

**SSL Protocol**
* [OpenSSL](https://www.openssl.org/)
* [Generate an OpenSSL Certificate Signing Request](https://phoenixnap.com/kb/generate-openssl-certificate-signing-request)

**Webserver's services**

* [MySQL](https://www.mysql.com/)
* [phpMyAdmin](https://www.phpmyadmin.net/)
* [WordPress](https://wordpress.org/)
