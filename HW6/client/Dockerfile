FROM python:latest

WORKDIR /client/app/

COPY requirements.txt .
RUN pip3 install -r requirements.txt

COPY app/client.py .

CMD ["python3","./client.py"]