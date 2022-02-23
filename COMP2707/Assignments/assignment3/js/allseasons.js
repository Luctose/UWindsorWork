/*
Assignment 3
COMP-2707
By: Lucas Sarweh
February 16th 2022
*/

// Called when the onchange event occurs for the select element
function changepic(){
    
    let pic = document.getElementById('pic'); // Img tag element
    let select = document.getElementById('season'); // Select tag element

    if(select.value=="winter") // Change to winter pic when value is such
        pic.src="C:\\Users\\lucas\\Desktop\\UwindsorWork\\COMP2707\\Assignments\\assignment3\\pictures\\winter.jpg";
    else if(select.value=="summer") // Change to summer pic when value is such
        pic.src="C:\\Users\\lucas\\Desktop\\UwindsorWork\\COMP2707\\Assignments\\assignment3\\pictures\\summer.jpg";
    else if(select.value=="spring") // Change to spring pic when value is such
        pic.src="C:\\Users\\lucas\\Desktop\\UwindsorWork\\COMP2707\\Assignments\\assignment3\\pictures\\spring.jpg";
    else if(select.value=="fall") // Change to fall pic when value is such
        pic.src="C:\\Users\\lucas\\Desktop\\UwindsorWork\\COMP2707\\Assignments\\assignment3\\pictures\\fall.jpg";
}