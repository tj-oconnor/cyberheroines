FROM php:7.4-apache
WORKDIR /var/www/html
COPY src/ /var/www/html/
RUN chmod +x /var/www/html/cyberheroines.sh && /var/www/html/cyberheroines.sh
RUN chown -R root:root /var/www/html/
RUN chmod -R o-w /var/www/html/

EXPOSE 80

CMD ["apache2-foreground"]