<script>
  document.addEventListener("DOMContentLoaded", () => {
    const yearSpan = document.getElementById("year");
    if(yearSpan) {
      yearSpan.textContent = new Date().getFullYear();
    }
  });
</script> function showAlert() {
    alert('More details coming soon!');
}

// Optional: Prevent form submission for demo purposes
document.getElementById('contact-form').addEventListener('submit', function(event) {
    event.preventDefault();
    alert('Message sent!');
});


