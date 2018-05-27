#include <cv.h>  
#include <cxcore.h>
#include <highgui.h>
 
int main()
{      
    int key = 0;
  
    // Initialize camera or OpenCV image
    //CvCapture* capture = cvCaptureFromCAM( 0 );
    CvCapture* capture = cvCaptureFromAVI( "dataset/video.avi" );  
    IplImage* frame = cvQueryFrame( capture );
 
    // Check 
    if ( !capture ) 
    {
        fprintf( stderr, "Cannot open AVI!\n" );
        return 1;
    }
 
    // Get the fps, needed to set the delay
    int fps = ( int )cvGetCaptureProperty( capture, CV_CAP_PROP_FPS );
  
    // Create a window to display the video
    cvNamedWindow( "video", CV_WINDOW_AUTOSIZE );
  
    while( key != 'x' ) 
    {
        // get the image frame 
        frame = cvQueryFrame( capture );
  
        // exit if unsuccessful
        if( !frame ) break;
        
        // display current frame 
        cvShowImage( "video", frame );
  
        // exit if user presses 'x'        
        key = cvWaitKey( 1000 / fps );
    }
  
    // Tidy up
    cvDestroyWindow( "video" );
    cvReleaseCapture( &capture );
 
    return 0;
}
