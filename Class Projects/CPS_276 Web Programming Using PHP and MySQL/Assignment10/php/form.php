<?php

//WRITE YOUR CODE HERE
class myForm
{
    //A super long array! it matches the form, which is another very long variable of string type. 
    private $elementsArr = [
        "masterStatus" => [
            "status" => "noerrors",
            "type" => "masterStatus"
        ],
        "name" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'>Name cannot be blank o start with a space. It must be a standard name</span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "name"
        ],
        "address" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'> Invalid address </span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "address"
        ],
        "city" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'> Enter a valid city</span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "city"
        ],
        "phone" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'>Enter a valid number with format 111.111.1111 </span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "phone"
        ],
        "state" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'>Please select a state</span>",
            "errorOutput" => "",
            "type" => "text",
            "selected" => "",
            "action" => "required",
            "value" => "",
            "regex" => "state"
        ],
        "email" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'> Enter a valid email i.e user@example.com </span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "email"
        ],
        "dob" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'>Enter a valid date in the format dd/mm/yyyy </span>",
            "errorOutput" => "",
            "type" => "text",
            "action" => "required",
            "value" => "",
            "regex" => "dob"
        ],
        "contact" => [
            "errorMessage" => "Select one",
            "errorOutput" => "",
            "type" => "text",
            "action" => "not required",
            "value" => "",
            "regex" => ""
        ],
        "age_range" => [
            "errorMessage" => "<span style='color: red; margin-left: 15px;'>Must select an age range</span>",
            "errorOutput" => "",
            "action" => "required",
            "type" => "text",
            "value" => "",
            "regex" => "age_range"
        ]
    ];


    //Use the returnForm() function to get a form up to date. simply pass an updated array.
    private function returnForm($arr)
    {

        /*        First, a few variables for the dropdown menu, radios, and checkboxes.
        I created them to utlilize the checked/selected attributes and make the form sticky for these particular fields
        Also, this way $_POST always has a value for these elements, or you get some errors.
        For example, sticky class will say index['radio] does not exist if someone submits without selecting an option. */

        $selected_MI = ($arr['state']['value'] == "MI" ? "selected" : "");
        $selected_CA = ($arr['state']['value'] == "CA" ? "selected" : "");
        $selected_FL = ($arr['state']['value'] == "FL" ? "selected" : "");
        $selected_OR = ($arr['state']['value'] == "OR" ? "selected" : "");
        $selected_WA = ($arr['state']['value'] == "WA" ? "selected" : "");
        $selected_state_hidden = ($arr['state']['value'] == "" ? "selected" : "");

        $checked_contact_newsletter = "";
        $checked_contact_text = "";
        $checked_contact_email = "";
        //there is also a secret hidden checkbox, but it must always be checked to ensure $_POST always has this index.
        //unlike the radio buttons or drop menu, we could have a condition with zero values, and it would cause problems.

        //if this is an array, it means $_POST is set, so we go differently about it
        if (is_array($arr['contact']['value'])) {
            foreach ($arr['contact']['value'] as $checkbox) {
                //A switch statement was easier here because of the loop.
                switch ($checkbox) {
                    case "Newsletter":
                        $checked_contact_newsletter = "checked";
                        break;
                    case "Text Updates":
                        $checked_contact_text = "checked";
                        break;
                    case "Email Updates":
                        $checked_contact_email = "checked";
                        break;
                }
            }
        }

        $selected_10_18 = ($arr['age_range']['value'] == "10-18" ? "checked" : "");
        $selected_19_30 = ($arr['age_range']['value'] == "19-30" ? "checked" : "");
        $selected_31_50 = ($arr['age_range']['value'] == "31-50" ? "checked" : "");
        $selected_51 = ($arr['age_range']['value'] == "51+  " ? "checked" : "");
        $selected_hidden = ($arr['age_range']['value'] == "" ? "checked" : "");

        //Variable for form...... just a long long string
        $formString = <<<HTML
        <form method="POST" action="index.php?page=form">
            <div class="form-group">
                <div class="form-row">
                    <label for="inputName">Name {$arr['name']['errorOutput']}</label>
                    <input type="text" class="form-control" id="inputName" name="name" value="{$arr['name']['value']}">
                </div>
                <div class="form-row">
                    <label for="inputStreet">Address (just number and street) {$arr['address']['errorOutput']}</label>
                    <input type="text" class="form-control" id="inputStreet" name="address" value="{$arr['address']['value']}">
                </div>
                <div class="form-row">
                    <label for="inputCity">City {$arr['city']['errorOutput']} </label>
                    <input type="text" class="form-control" id="inputCity" name="city" value="{$arr['city']['value']}">
                </div>
                <div class="form-row">
                    <label for="InputState">State {$arr['state']['errorOutput']} </label>
                    <select class="form-control" id="InputState" name="state" {$arr['state']['value']}>
                        <option value="MI" $selected_MI>MI</option>
                        <option value="CA" $selected_CA>CA</option>
                        <option value="FL" $selected_FL>FL</option>
                        <option value="OR" $selected_OR>OR</option>
                        <option value="WA" $selected_WA>WA</option>
                        <option value="" style="display:none" $selected_state_hidden></option>
                    </select>
                </div>
                <div class="form-row">
                    <label for="inputPhone">Phone {$arr['phone']['errorOutput']} </label>
                    <input type="text" class="form-control" id="inputPhone" name="phone" value="{$arr['phone']['value']}">
                </div>
                <div class="form-row">
                    <label for="inputEmail">Email Address {$arr['email']['errorOutput']} </label>
                    <input type="email" class="form-control" id="inputEmail" name="email" value="{$arr['email']['value']}">
                </div>
                <div class="form-row">
                    <label for="inputDOB">Date of birth {$arr['dob']['errorOutput']} </label>
                    <input type="text" class="form-control" id="inputDOB" name="dob" value="{$arr['dob']['value']}">
                </div>
                </br>
                <label class="form-check-label" for="contactType"> Please check all contact types you would like (optional) {$arr['contact']['errorOutput']} </label>
                <div class="form-row" id="contactType">
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="checkbox" id="newsletterCheck" value="Newsletter" name="contact[]" $checked_contact_newsletter>
                        <label class="form-check-label" for="newsletterCheck">Newsletter</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="checkbox" id="emailCheck" value="Email Updates" name="contact[]" $checked_contact_email>
                        <label class="form-check-label" for="emailCheck">Email Updates</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="checkbox" id="textCheck" value="Text Updates" name="contact[]" $checked_contact_text>
                        <label class="form-check-label" for="textCheck">Text Updates </label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="checkbox" id="textCheck" value="" name="contact[]" style="display:none" checked>
                    </div>
                </div>
                </br>
                <label class="form-check-label" for="ageRange"> Please select an age range (you must select one) {$arr['age_range']['errorOutput']} </label>
                <div class="form-row" id="ageRange">
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" id="1018Radio" value="10-18" name="age_range" $selected_10_18 {$arr['age_range']['value']} >
                        <label class="form-check-label" for="1018Radio" >10-18</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" id="1930Radio" value="19-30" name="age_range" $selected_19_30 {$arr['age_range']['value']} >
                        <label class="form-check-label" for="1930Radio">19-30</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" id="3150Radio" value="31-50" name="age_range" $selected_31_50 {$arr['age_range']['value']}>
                        <label class="form-check-label" for="3150Radio">31-50</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" id="51Radio" value="51+  " name="age_range" $selected_51 {$arr['age_range']['value']}>
                        <label class="form-check-label" for="51Radio">51+</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" id="place_holder" value="" name="age_range" style="display:none" $selected_hidden>
                    </div>
                </div>
                </br>
                <div class="form-row">
                    <button type="submit" name="submit" class="btn btn-primary">Submit</button>
                </div>
        </form>
        HTML;

        return $formString;
    }

    //Pass the global variable $elementsArr and get a blank form. 
    public function returnBlankForm()
    {
        return array("<h5><strong>Please enter the contact info</strong></h5>", $this->returnForm($this->elementsArr));
    }

    /*It changes a date from format 11/11/1111 => 1111-11-11
    It is required due since it will be store as the date datatype inside mysql  */
    public function prepDate(&$rawDate)
    {
        $temp = explode('/', $rawDate);
        $temp = array_reverse($temp);
        $rawDate = implode('-', $temp);
    }

    /*It prepares the contact type inside $_POST, which is a sub array, 
    and turns it into a string for storage in the database */
    public function prepContactType(&$contact)
    {
        $temp = $contact;
        if (is_array($temp))
            $contact = implode(', ', $temp);
    }

    public function processForm()
    {
        require_once "classes/StickyForm.php";
        require_once "classes/Pdo_methods.php";

        $toDB = new DBInputOutput();
        $checkForm = new StickyForm();
        $validatedArray = null;
        $toDatabaseArray = null;
        $check = false;

        /*checking the data in $_POST for user errors.  validateForm() returns and array
        with errors, along the original data.  This is what makes the form sticky */
        $validatedArray = $checkForm->validateForm($_POST, $this->elementsArr);

        if ($validatedArray['masterStatus']['status'] == "error")
            return array("<h5><strong>Sorry, one or more fields contain invalid data </strong></h5>", $this->returnForm($validatedArray));

        else if ($validatedArray['masterStatus']['status'] == "noerrors") {

            //If there are not erros, change the formatting again just so that the database can take it.
            $this->prepDate($_POST['dob']);
            $this->prepContactType($_POST['contact']);

            /*Create an array where the index names match the columns in the database.
            Coincidentally, $_POST already has matching names, but I like doing it this way
            Just in case I need to change something in the form, the db does not have to change. */
            $toDatabaseArray = array(
                'name' => $_POST['name'],
                'address' => $_POST['address'],
                'city' => $_POST['city'],
                'state' => $_POST['state'],
                'phone' => $_POST['phone'],
                'email' => $_POST['email'],
                'dob' => $_POST['dob'],
                'contact' => $_POST['contact'],
                'age_range' => $_POST['age_range'],
            );

            //pass the array and the name, the function will take care of the rest.
            $check = $toDB->insertData('final', $toDatabaseArray);

            if ($check ==  "NO ERROR")
                return array("<h5><strong>Contact added succesfully</strong></h5>", $this->returnForm($this->elementsArr));
            else
                return array("<h5><strong>Something went wrong: $check </strong></h5>", $this->returnForm($this->elementsArr));
        }
    }
}
