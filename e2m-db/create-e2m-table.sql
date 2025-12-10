-- Create table for e2m file data
CREATE TABLE IF NOT EXISTS public.e2m_data (
    id SERIAL PRIMARY KEY,
    file_name VARCHAR(255) NOT NULL,
    full_name VARCHAR(255),
    engineering_unit VARCHAR(50),
    memory_block_address VARCHAR(10),
    memory_block_offset VARCHAR(10),
    memory_region_identifier VARCHAR(10),
    type VARCHAR(10),
    access_control VARCHAR(10),
    length VARCHAR(10),
    precision_val VARCHAR(10),
    signed_type VARCHAR(10),
    scale VARCHAR(20),
    minimum_value VARCHAR(20),
    subfile_number VARCHAR(10),
    group_id VARCHAR(10),
    unknown_column VARCHAR(20),
    enum_values TEXT,
    comment TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Create index on file_name for better query performance
CREATE INDEX IF NOT EXISTS idx_e2m_data_file_name ON public.e2m_data(file_name);

-- Create index on full_name for parameter lookups
CREATE INDEX IF NOT EXISTS idx_e2m_data_full_name ON public.e2m_data(full_name);

-- Create index on type for grouping queries
CREATE INDEX IF NOT EXISTS idx_e2m_data_type ON public.e2m_data(type);