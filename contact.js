document.addEventListener('DOMContentLoaded', function() {
    const contactInfo = document.getElementById('contact-info');

    const email = ' agomiyabisrat@gmail.com';
    const phone = '+251904084966';
    const github = 'https://github.com/@AGOMIYA';
    const telegram = 'https://t.me/@agomiya'; 
    const contactLinks = 
        
   
        <><h2>Contact Information</h2><ul>
            <li>Email: <a href="mailto:${email}">${email}</a></li>
            <li>Phone: <a href="tel:${phone}">${phone}</a></li>
            
        </ul></>
    ;
 

    contactInfo.innerHTML = contactLinks;
});
