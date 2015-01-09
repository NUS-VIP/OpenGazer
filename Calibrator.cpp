#include "Calibrator.h"
#include <fstream>
#include "Global.h"
#include <iostream>
#include "utils.h"
//#include "opencv2/imgproc/imgproc.hpp"

Calibrator::~Calibrator() {
#ifdef DEBUG
    cout << "Destroying calibrator" << endl;
#endif
}

FrameFunction::~FrameFunction() {
#ifdef DEBUG
    cout << "Destroying framefunction" << endl;
#endif
}

MovingTarget::MovingTarget(const int &frameno,
			   const vector<Point>& points,
			   const shared_ptr<WindowPointer> &pointer,
			   int dwelltime):
    FrameFunction(frameno),
    points(points), dwelltime(dwelltime), pointer(pointer)
{
};

MovingTarget::~MovingTarget() {
    int id = getFrame() / dwelltime;
}

void MovingTarget::process() {
    if (active()) {
	int id = getPointNo();
	if (getPointFrame() == 1)
	    pointer->setPosition((int)points[id].x, (int)points[id].y);

	    cout<< points[id].x << "," <<points[id].y<<"\n";

// wirte to a file
    if(isCalibrating)
{
    char fixedpoint [50];
    sprintf (fixedpoint, "%.2lf  %.2lf \n",points[id].x,points[id].y);
    ofstream myfile;
    myfile.open ("CP.txt",fstream::app);
    myfile << fixedpoint;
    myfile.close();
}

    if(isTesting)
{
    char fixedpoint [50];
    sprintf (fixedpoint, "%.2lf  %.2lf \n",points[id].x,points[id].y);
    ofstream myfile;
    myfile.open ("target.txt",fstream::app);
    myfile << fixedpoint;
    myfile.close();
}
    }
    else
	detach();
}

bool MovingTarget::active() {
    return getPointNo() < (int) points.size();
}

int MovingTarget::getPointNo() {
    return getFrame() / dwelltime;
}

int MovingTarget::getPointFrame() {
    return getFrame() % dwelltime;
}

Calibrator::Calibrator(const int &framecount,
		       const shared_ptr<TrackingSystem> &trackingsystem,
		       const vector<Point>& points,
		       const shared_ptr<WindowPointer> &pointer,
		       int dwelltime):
    MovingTarget(framecount, points, pointer, dwelltime),
    trackingsystem(trackingsystem)
{
    trackingsystem->gazetracker.clear();
    // todo: remove all calibration points
}


void Calibrator::process() {
    if (active()) {
	int id = getPointNo();
	int frame = getPointFrame();
	if (frame == 1) // start
	    averageeye.reset(new FeatureDetector(EyeExtractor::eyesize));

	if (frame >= dwelltime/2) // middle
	    averageeye->addSample(trackingsystem->eyex.eyefloat.get());

	if (frame == dwelltime-1) { // end
	    trackingsystem->gazetracker.
		addExemplar(points[id], averageeye->getMean().get(),
			    trackingsystem->eyex.eyegrey.get());

			    //print out eye image in matrix form
			    cv::Mat Matrix(trackingsystem->eyex.eyegrey.get());
                //cv::Mat Matrixdown;
                //cv::Mat tmp;
                //tmp = Matrix;
			    //pyrDown(tmp,Matrixdown,cv::Size(tmp.cols/2, tmp.rows/2));
                ofstream file;
                file.open("EyeMatrix.txt",fstream::app);
                file<< Matrix<<endl;
                file.close();
	}
    }
    MovingTarget::process();
}
//13 calibration points
/*const Point Calibrator::defaultpointarr[] = {Point(0.5, 0.5),
					     Point(0.1, 0.5), Point(0.9, 0.5),
					     Point(0.5, 0.1), Point(0.5, 0.9),
					     Point(0.1, 0.1), Point(0.1, 0.9),
					     Point(0.9, 0.9), Point(0.9, 0.1),
					     Point(0.3, 0.3), Point(0.3, 0.7),
					     Point(0.7, 0.7), Point(0.7, 0.3)};
*/
//36 calibration points
/*const Point Calibrator::defaultpointarr[] = {Point(0.0, 0.0),
					     Point(0.0, 0.2), Point(0.0, 0.4),
					     Point(0.0, 0.6), Point(0.0, 0.8),
					     Point(0.0, 0.9), Point(0.2, 0.0),
					     Point(0.2, 0.2), Point(0.2, 0.4),
					     Point(0.2, 0.6), Point(0.2, 0.8),
					     Point(0.2, 0.9), Point(0.4, 0.0),
					     Point(0.4, 0.2), Point(0.4, 0.4),
					     Point(0.4, 0.6), Point(0.4, 0.8),
					     Point(0.4, 0.9), Point(0.6, 0.0),
					     Point(0.6, 0.2), Point(0.6, 0.4),
					     Point(0.6, 0.6), Point(0.6, 0.8),
					     Point(0.6, 0.9), Point(0.8, 0.0),
					     Point(0.8, 0.2), Point(0.8, 0.4),
					     Point(0.8, 0.6), Point(0.8, 0.8),
					     Point(0.8, 0.9), Point(0.9, 0.0),
					     Point(0.9, 0.2), Point(0.9, 0.4),
					     Point(0.9, 0.6), Point(0.9, 0.8),
					     Point(0.9,0.9)};
*/
const Point Calibrator::defaultpointarr[] = {Point(0.0, 0.0),Point(0.0, 0.15),
					     Point(0.0, 0.3), Point(0.0, 0.45),
					     Point(0.0, 0.6), Point(0.0, 0.75),
					     Point(0.0, 0.9), Point(0.15, 0.0),
					     Point(0.15, 0.15), Point(0.15, 0.3),Point(0.15, 0.45),
					     Point(0.15, 0.6), Point(0.15, 0.75),
					     Point(0.15, 0.9), Point(0.3, 0.0),
					     Point(0.3, 0.15), Point(0.3, 0.3),
					     Point(0.3, 0.45), Point(0.3, 0.6),
					     Point(0.3, 0.75),Point(0.3, 0.9),Point(0.6, 0.0),
					     Point(0.6, 0.15), Point(0.6, 0.3),
					     Point(0.6, 0.45),Point(0.6, 0.6), Point(0.6, 0.75),
					     Point(0.6, 0.9), Point(0.75, 0.0),
					     Point(0.75, 0.15), Point(0.75, 0.3),
					     Point(0.75, 0.45),Point(0.75, 0.6), Point(0.75, 0.75),
					     Point(0.75, 0.9), Point(0.9, 0.0),
					     Point(0.9, 0.15), Point(0.9, 0.3),
					     Point(0.9, 0.45),Point(0.9, 0.6), Point(0.9, 0.75),
					     Point(0.9,0.9)};
vector<Point>
Calibrator::defaultpoints(Calibrator::defaultpointarr,
			  Calibrator::defaultpointarr+
			  (sizeof(Calibrator::defaultpointarr) /
			   sizeof(Calibrator::defaultpointarr[0])));

vector<Point> Calibrator::loadpoints(istream& in) {
    vector<Point> result;

    for(;;) {
	double x, y;
	in >> x >> y;
	if (in.rdstate()) break; // break if any error
	result.push_back(Point(x, y));
    }

    return result;
}

vector<Point> Calibrator::scaled(const vector<Point> &points,
				      double x, double y)
{
//     double dx = x > y ? (x-y)/2 : 0.0;
//     double dy = y > x ? (y-x)/2 : 0.0;
//     double scale = x > y ? y : x;

    vector<Point> result;

    xforeach(iter, points)
	result.push_back(Point(iter->x * x, iter->y * y));
// 	result.push_back(Point(iter->x * scale + dx, iter->y * scale + dy));

    return result;
}
