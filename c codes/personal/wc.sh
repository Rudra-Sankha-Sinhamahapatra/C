# Prompt the user to enter the file name
echo "Enter the file name:"
read file_name

# Check if the file exists
if [ -f "$file_name" ]; then
  # Count the number of lines
  num_lines=$(wc -l < "$file_name")

  # Count the number of words
  num_words=$(wc -w < "$file_name")

  # Print the results
  echo "Number of lines: $num_lines"
  echo "Number of words: $num_words"
else
  # File not found
  echo "File not found: $file_name"
fi