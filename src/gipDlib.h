/*
 * gipDlib.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Noyan Culum
*/

#ifndef SRC_GIPDLIB_H_
#define SRC_GIPDLIB_H_

#include "gBaseComponent.h"
#include "dlib/image_processing/frontal_face_detector.h"
#include "dlib/image_processing/shape_predictor.h"
#include "dlib/opencv/cv_image.h"


class gipDlib : public gBaseComponent{
public:
	gipDlib();
	virtual ~gipDlib();

	void loadData(std::string fullFilepath);
	void loadDataFile(std::string filename);

	void loadImage(std::string fullImagepath);
	void setImage(dlib::array2d<dlib::rgb_pixel>& img);
	void setOpenCVMat(cv::Mat& ocvMat);

	int detectFaces();
	std::vector<dlib::rectangle> getFaces();
	int getFaceNum();
	dlib::rectangle getFace(int faceNo);

	int detectShapes();
	std::vector<dlib::full_object_detection> getShapes();
	int getShapesNum();
	dlib::full_object_detection getShape(int shapeNo);

private:
	dlib::frontal_face_detector detector;
	dlib::shape_predictor predictor;

	dlib::array2d<dlib::rgb_pixel> image;

	std::vector<dlib::rectangle> faces;
	std::vector<dlib::full_object_detection> shapes;
};

#endif /* SRC_GIPDLIB_H_ */
