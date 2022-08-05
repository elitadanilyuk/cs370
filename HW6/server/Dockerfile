FROM python:latest

WORKDIR /server/app/

COPY requirements.txt .
RUN pip3 install -r requirements.txt

COPY app/server.py .
# CMD ["python3","-m","flask","run","--host=0.0.0.0"]
CMD ["python3","./server.py","--host=0.0.0.0"]