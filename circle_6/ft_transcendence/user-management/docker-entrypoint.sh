set -e
python manage.py makemigrations social_login friends
python manage.py migrate social_login
python manage.py migrate friends

gunicorn -b 0.0.0.0 -p 8000 --access-logfile ./access.log userManagement.wsgi:application
