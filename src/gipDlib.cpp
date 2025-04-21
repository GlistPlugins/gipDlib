/*
 * gipDlib.cpp
 *
 *  Created on: Apr 18, 2025
 *      Author: Noyan Culum
 */

#include "gipDlib.h"


gipDlib::gipDlib() {
	detector = dlib::get_frontal_face_detector();
}

gipDlib::~gipDlib() {
}

void gipDlib::loadData(std::string fullFilepath) {
	dlib::deserialize(fullFilepath) >> predictor;
}

void gipDlib::loadDataFile(std::string filepath) {
	loadData(gGetFilesDir() + filepath);
}

void gipDlib::loadImage(std::string fullImagepath) {
}

void gipDlib::setImage(dlib::array2d<dlib::rgb_pixel>& img) {
//	image = img;
}

void gipDlib::setOpenCVMat(cv::Mat& ocvMat) {
	dlib::assign_image(image, dlib::cv_image<dlib::bgr_pixel>(ocvMat));
}

int gipDlib::detectFaces() {
	faces = detector(image);
	return faces.size();
}

std::vector<dlib::rectangle> gipDlib::getFaces() {
	return faces;
}

int gipDlib::getFaceNum() {
	return faces.size();
}

dlib::rectangle gipDlib::getFace(int faceNo) {
	return faces[faceNo];
}

int gipDlib::detectShapes() {
	shapes.clear();
	if(!faces.empty()) {
		for(int i = 0; i < faces.size(); i++) {
			dlib::full_object_detection shape = predictor(image, faces[i]);
			shapes.push_back(shape);
		}
	}
	return shapes.size();
}

std::vector<dlib::full_object_detection> gipDlib::getShapes() {
	return shapes;
}

int gipDlib::getShapesNum() {
	return shapes.size();
}

dlib::full_object_detection gipDlib::getShape(int shapeNo) {
	return shapes[shapeNo];
}

