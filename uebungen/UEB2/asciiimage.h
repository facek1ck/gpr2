#ifndef _ASCIIIMAGE_HEADER_
#define _ASCIIIMAGE_HEADER_

class myAscii{
    public:
        myAscii(int width, int height);
        ~myAscii();
        void setPix(int x, int y, int color);
        void show();
	
	#ifdef TESTS
		public:
	#else
		private:
	#endif
        int width;
        int height;
        char **pic;
};

#endif

