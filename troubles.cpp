/*
construction like this doesn't work
*/
friend Vec :: Vec operator+(const Vec& other){
    return Vec (this->X + other.X,
                this->Y + other.Y,
                this->Z + other.Z);
}

// but this works

friend Vec :: Vec operator+(const Vec& other){
    Vec v(this->X + other.X,
          this->Y + other.Y,
          this->Z + other.Z);
    return v;
}
