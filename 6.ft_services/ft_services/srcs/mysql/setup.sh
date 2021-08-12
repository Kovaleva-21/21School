openrc default
/etc/init.d/mariadb setup
rc-service mariadb start
mariadb < mysql.sql 
mysql -u root wordpress < wordpress.sql
rc-service mariadb stop
/usr/bin/mysqld_safe --datadir='/var/lib/mysql'