[%bs.raw {|require('./footer.css')|}];

let component = ReasonReact.statelessComponent "Footer";

let make _children => {  
  {
    ...component,
    render: fun self =>
      <footer className="footer">
        <h3 className="flex-1">(ReasonReact.stringToElement "Footer")</h3>
        <div className="flex flex-end center">
          <FontAwesome name="github"/>
        </div>
      </footer>
  }
};
