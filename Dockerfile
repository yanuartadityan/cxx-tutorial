FROM ubuntu:22.04

# Set local user as container user
ARG USER_NAME
ARG USER_UID
ARG USER_GID
RUN groupadd --gid $USER_GID $USER_NAME
RUN useradd --uid $USER_UID --gid $USER_GID $USER_NAME

# Update environment
RUN apt-get update && \
	apt-get install -y \
	build-essential \
	g++ \
	cmake \
	libboost-all-dev \
	libeigen3-dev
RUN echo "Copying..."
WORKDIR /proj
COPY . .
RUN ls

# Building
RUN echo "Building..."
WORKDIR /proj/build 
RUN pwd
RUN cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
RUN make
