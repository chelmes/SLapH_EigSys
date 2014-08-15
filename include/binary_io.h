//everything that can be written and read goes here
class bin_io {
  public:
    void read();
    
  private:
    //reading functions for matrix, vector and gauge field from binary file
    void read_matrix_bin();
    void read_vector_bin();
    void read_gauge_field_bin();

    //writing functions for matrix and vector
    void write_matrix_bin();
    void write_vector_bin();

};
