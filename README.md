<section id="c-assignment-1">
  <h1>GPA Calculation App (C)</h1>

  <h2>Description</h2>
  <p>
    A C console application that manages a student’s course list using an array of structures, supports
    menu-driven operations (update, display, max grade, GPA calculation), reads input from a file, and
    saves results to an output file.
  </p>

  <h2>Features</h2>
  <ul>
    <li>Defines a <code>Course</code> struct (courseID, credits, grade) and stores courses in a fixed-size array (<code>MAX_COURSES</code>)</li>
    <li>Reads course data from an input file (e.g., <code>grades.txt</code>) before running menu operations</li>
    <li>Updates a course grade with validation</li>
    <li>Finds the maximum grade using recursion (<code>findMaxGrade</code> + <code>max</code>)</li>
    <li>Computes accumulative GPA using a grade-points conversion function</li>
    <li>Saves course results to <code>output.txt</code></li>
  </ul>

  <h2>Tech Stack</h2>
  <ul>
    <li><strong>C</strong> &ndash; Core language (structs, arrays, recursion, file I/O)</li>
    <li><strong>Standard C Libraries</strong> &ndash; For input/output and file handling</li>
  </ul>

  <h2>What I Learned</h2>
  <ul>
    <li>Using arrays of structs to model real data in C</li>
    <li>Reading from and writing to files in C</li>
    <li>Implementing recursion for finding a maximum value</li>
    <li>Building a menu-driven console program with multiple operations</li>
  </ul>

  <h2>Screenshots</h2>
  <p>
    Add 1&ndash;2 screenshots (or terminal captures) showing:
    <br />
    <em>(1) Menu options and (2) GPA output / file save confirmation</em>
  </p>

  <h2>How to Run</h2>
  <ol>
    <li>
      Clone this repository:
      <pre><code>git clone https://github.com/ahtran99/C-Assignment1-repo.git</code></pre>
    </li>
    <li>
      Navigate to the project directory:
      <pre><code>cd C-Assignment1-repo</code></pre>
    </li>
    <li>
      Ensure the input file exists (e.g., <code>grades.txt</code>) in the expected location.
    </li>
    <li>
      Compile:
      <pre><code>gcc main.c -o gpa_app</code></pre>
    </li>
    <li>
      Run:
      <pre><code>./gpa_app</code></pre>
    </li>
  </ol>

  <h2>Notes</h2>
  <p>
    <strong>Originally built as part of a Sheridan College assignment.</strong><br />
    The assignment required file input (<code>grades.txt</code>), menu-driven updates, recursive max-grade search,
    GPA computation, and saving results to <code>output.txt</code>.
  </p>
</section>
