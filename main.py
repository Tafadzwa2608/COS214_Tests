import os

def extract_cpp_code(root_dir=".", output_file="extracted_code.txt"):
    """
    Extract C++ code from .cpp and .h files in the specified directory.
    
    Args:
        root_dir: Directory to search (default: current directory)
        output_file: Output text file name
    """
    extensions = {'.cpp', '.h', '.hpp', '.cc', '.cxx', '.hxx'}
    files_processed = 0
    
    print(f"Searching for C++ files in: {os.path.abspath(root_dir)}")
    
    with open(output_file, 'w', encoding='utf-8') as outfile:
        for root, dirs, files in os.walk(root_dir):
            # Skip the script itself and common directories
            skip_dirs = {'build', '.git', 'node_modules', '__pycache__'}
            dirs[:] = [d for d in dirs if d not in skip_dirs]
            
            for file in files:
                # Skip the extractor script
                if file == os.path.basename(__file__):
                    continue
                    
                file_ext = os.path.splitext(file)[1].lower()
                
                if file_ext in extensions:
                    file_path = os.path.join(root, file)
                    relative_path = os.path.relpath(file_path, root_dir)
                    
                    try:
                        with open(file_path, 'r', encoding='utf-8') as infile:
                            outfile.write(f"\n{'=' * 60}\n")
                            outfile.write(f"FILE: {relative_path}\n")
                            outfile.write(f"{'=' * 60}\n\n")
                            
                            content = infile.read()
                            outfile.write(content)
                            
                            if content and not content.endswith('\n'):
                                outfile.write('\n')
                            
                            files_processed += 1
                            print(f"✓ Added: {relative_path}")
                            
                    except UnicodeDecodeError:
                        # Try with different encoding
                        try:
                            with open(file_path, 'r', encoding='latin-1') as infile:
                                outfile.write(f"\n{'=' * 60}\n")
                                outfile.write(f"FILE: {relative_path}\n")
                                outfile.write(f"{'=' * 60}\n\n")
                                outfile.write(infile.read())
                                outfile.write('\n')
                                files_processed += 1
                                print(f"✓ Added: {relative_path}")
                        except Exception as e:
                            print(f"✗ Error reading {relative_path}: {e}")
                    except Exception as e:
                        print(f"✗ Error processing {relative_path}: {e}")
    
    print(f"\n✅ Done! Processed {files_processed} files")
    print(f"📁 Output: {output_file}")

# For your specific case - choose one:

# If script is in same directory as C++ files:
if __name__ == "__main__":
    extract_cpp_code(".")  # Current directory

# If script is in parent directory of src folder:
# if __name__ == "__main__":
#     extract_cpp_code("./src")  # src subdirectory