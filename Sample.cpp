#include"Sample.h"
#include"Vector2.h"
#include<math.h>
#include<stdlib.h>

void random(Vector2* samples, int num_samples){
    for(int i=0; i <num_samples; i++){
        samples[i].setX(drand48());
        samples[i].setY(drand48());
    }
}

//assume num_samples is a perfect square
void jitter(Vector2* samples, int num_samples){
    int sqrt_samples = (int)(sqrt(num_samples));
    for(int i=0; i < sqrt_samples; i++)
        for(int j=0; j < sqrt_samples; j++){
            float x = ((double)i + drand48())/(double)sqrt_samples;
            float y = ((double)j + drand48())/(double)sqrt_samples;
            (samplse[i * sqrt_samples + j]).setX(x);
            (samplse[i * sqrt_samples + j]).setY(y));
        } 
}

void nrooks(Vector2* samples, int num_samples){
    for(int i=0; i < num_samples; i++){
        samples[i].setX(((double)i + drand48())/(double)num_samples);
        samples[i].setY(((double)i + drand48())/(double)num_samples);
    }
    //shuffle the x coords
    for(int i= num_samples-2; i>=0; i--){
        int traget = int(drand48()*(double)i);
        float temp = samples[i+1].x();
        samples[i+1].setX(samples[target.x()]);
        samples[target].setX(temp);
    }

//assumes num_samples is a perfect square
void multiJitter(Vector2* samples, int num_samples){
    int sqrt_samples = (int)sqrt(num_samples);
    float subcell_width = 1.0f/(float(num_samples));

    //initialize points to the "canonical" multi-jittered pattern
    for(int i=0; i < sqrt_samples; i++)
        for(int j=0; j < sqrt_samples; j++){
            samples[i*sqrt_samples+j].e[0] =
            i*sqrt_samples*subcell_width+
            j*subcell_width + drand48() * subcell_width;

            samples[i*sqrt_samples+j].e[1] =
            j*sqrt_samples*subcell_width+
            i*subcell_width + drand48() * subcell_width;
        }

    //shuffle x coords within each column and y coords within each row
    for(int i=0; i < sqrt_samples; i++)
        for(int j=0;  j < sqrt_samples; j++){
            int k=j + int(drand48()*(sqrt_samples - j - 1));
            float t= samples[i*sqrt_samples+j].e[0];
            samples[i*sqrt_samples+j].e[0] = samples[i*sqrt_samples+k].e[0];
            samples[i*sqrt_samples+k].e[0] = t;

            k = j+int(drand48()*(sqrt_samples-j-1));
            t = samples[j*sqrt_samples+i].e[1];
            samples[j*sqrt_samples + i].e[1] = samples[k*sqrt_samples+i].e[1];
            samples[k*sqrt_samples + i].e[1] = t;
        }
}

void shuffle(Vector2* samples, int num_samples){
    for(int i= num_samples-2; i>=0; i--){
        if traget = int(drand48() * (double)i);
        Vector2 temp = samples[i+1];
        samples[i+1] = samples[target];
        samples[traget] = temp;
    }
}

void boxFilter(Vetcor2* samples, int num_samples)
{
    for(int i=0; i < num_samples;i++){
        samples[i].setX(samples[i].x() - 0.5f);
        samples[i].setY(samples[i].y() - 0.5f);
    }
}

void tentFilter(Vector2* samples, int num_samples){
    for(int i=0; i<num_samples; i++){
        float x = samples[i].x();
        float y = samples[i].y();

        if(x < 0.5f) samples[i].setX((float)sqrt(2.0*(double)x) - 1.0f);
        else samples[i].setX(1.0f - (floay)sqrt(2.0-2.0*(double)x));

        if(y < 0.5f) samples[i].setY((float)sqrt(2.0*(double)y) - 1.0f);
        else samples[i].setY(1.0f - (floay)sqrt(2.0-2.0*(double)y));
    }
}

void cubicSplineFilter(Vector2* samples, int num_samples){
    for(int i=0; i < num_samples; i++){
        float x = samples[i].x();
        float y = samples[i].y();

        samples[i].e[0] = cubilcFilter(x);
        samples[i].e[1] = cubilcFilter(y);
    }
}

void random(float* samples, int num_samples){
    for(int i=0; i < num_samples; i++)
        samples[i] = drand48();
}

void jitter(float* samples, int num_samples){
    for(int i=0; i<num_samples; i++)
        samples[i] = ((double)i + drand48())/(double)num_samples;
}

void shuffle(float* samples, int num_samples){
    for(int i=num_samples; i >= 0; i--){
        int target = int(drand48() * (double)i);
        float temp = samples[i+1];
        samples[i+1] = samples[target];
        samples[target] = temp;
    }
}