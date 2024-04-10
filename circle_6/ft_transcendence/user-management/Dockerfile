FROM python:3.11-alpine3.18

WORKDIR /app

COPY ./requirements.txt .

RUN apk add build-base libffi-dev
RUN pip3 install -r requirements.txt
RUN pip3 install psycopg2-binary

COPY . .

ENV DJANGO_SETTINGS_MODULE userManagement.settings

CMD ["/bin/sh", "docker-entrypoint.sh"]
