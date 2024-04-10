set -e
python manage.py makemigrations chatting
python manage.py migrate chatting

daphne -b 0.0.0.0 -p 8000 --access-log ./access.log config.asgi:application