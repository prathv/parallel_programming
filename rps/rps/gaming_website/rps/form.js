

window.onload = function(){

document.write("I am imported");
document.write(document.forms["Myform"]['fname'].value);

function validate() {

    var x=document.forms["myform"]["fname"].value;  
    if(x==null || x=="" )
    {
        alert("name can't be left blank");
			event.preventDefault();
	
        return false;
    }

    var y=document.forms["myform"]["lname"].value;
    if(y==null || y=="")
    {
        alert("last name is mandatory");
			event.preventDefault();

        return false;
    }



}
}
